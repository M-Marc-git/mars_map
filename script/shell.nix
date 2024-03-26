with import <nixpkgs> {};
mkShell {
	name = "MarsMap";

	buildInputs = [
		pkg-config
		meson
		python3Packages.pillow
	];

	nativeBuildInputs = [
		glfw3
		glew
	];
}
