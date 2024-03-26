with import <nixpkgs> {};
mkShell {
	name = "MarsMap";

	buildInputs = [
		pkg-config
		meson
	];

	nativeBuildInputs = [
		glfw3
		glew
	];
}
