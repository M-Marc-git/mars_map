#include "core/mars_map.h"

int main() {
    MarsMap* map = create_mars_map();
    run_mars_map(map);
    destroy_mars_map(map);
    return 0;
}
