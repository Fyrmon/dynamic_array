from conan import ConanFile
from conan.tools.cmake import cmake_layout
class Rec(ConanFile) :
    settings = "os","arch","build_type","compiler"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("gtest/1.17.0")
    
    def build_requirements(self):
        self.tool_requires("cmake/3.27.9")
    
    def layout(self):
        cmake_layout(self)


