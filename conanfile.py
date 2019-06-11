from conans import ConanFile


class WafExampleConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "Waf"

    def requirements(self):
        self.requires("openpnp-capture/0.0.17@czoido/testing")
        self.requires("opencv/4.1.0@conan/stable")
        self.requires("glfw/3.2.1@bincrafters/stable")
        self.requires("glew/2.1.0@bincrafters/stable")
        self.requires("WafGen/0.1@czoido/testing")
        self.requires("waf_installer/2.0.17@czoido/testing")

    def build_requirements(self):
        self.build_requires("waf_installer/2.0.17@czoido/testing")

    def build(self):
        self.run("waf configure")
        self.run("waf build")

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")  # From bin to bin
        self.copy("*.dylib*", dst="bin", src="lib")  # From lib to bin
