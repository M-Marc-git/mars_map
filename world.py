#!/usr/bin/python3
import logging
import threading
from typing import ParamSpecArgs
from PIL import Image

format = "%(asctime)s: %(message)s"
logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")

THREAD_COUNT = 4
TOP_LEFT_CORNER = [205, 385]
DOWN_RIGHT_CORNER = [11723, 6782]

MERIDIEN = [i for i in range(524, DOWN_RIGHT_CORNER[0], 320)]
PARALLELE = [j for j in range(402, DOWN_RIGHT_CORNER[1], 767)]

CHUNK_SIZE = 64

tasks = [[i,j] \
    for i in range(TOP_LEFT_CORNER[0], DOWN_RIGHT_CORNER[0], CHUNK_SIZE) \
    for j in range(TOP_LEFT_CORNER[1], DOWN_RIGHT_CORNER[1], CHUNK_SIZE)]

image = Image.open("mola_mercat.jpg")
pix_map = image.load()
mutex = threading.Lock()

def run_thread():
    logging.info("Lancement d'un thread")
    while(len(tasks) > 0):
        mutex.acquire()
        task = tasks.pop()
        mutex.release()

        make_image(task[0], task[1])

def make_image(i, j):
    logging.info("Chargement image %d %d", int((i-TOP_LEFT_CORNER[0])/64), int((j-TOP_LEFT_CORNER[1])/64))
    img = Image.new('RGB', (CHUNK_SIZE, CHUNK_SIZE), "black");
    pixels = img.load()

    for x in range(i, i+CHUNK_SIZE):
        for y in range(j, j+CHUNK_SIZE):
            pixels[x-i,y-j] = pix_map[x,y]
            for meridien in MERIDIEN:
                if(x == meridien):
                    pixels[x-i,y-j] = (pix_map[x,y-1]+pix_map[x,y+1])/2
                    continue
            for parallele in PARALLELE:
                if(y == PARALLELE):
                    pixels[x-i,y-j] = (pix_map[x,y-1]+pix_map[x,y+1])/2
    
    image_name = "assets/world/world_" + str(int((i-TOP_LEFT_CORNER[0])/64)) + "_" + str(int((j-TOP_LEFT_CORNER[1])/64)) + ".jpg"
    img.save(image_name)

thread0 = threading.Thread(target=run_thread)
thread1 = threading.Thread(target=run_thread)
thread2 = threading.Thread(target=run_thread)
thread3 = threading.Thread(target=run_thread)

thread0.start()
thread1.start()
thread2.start()
thread3.start()

thread0.join()
thread1.join()
thread2.join()
thread3.join()