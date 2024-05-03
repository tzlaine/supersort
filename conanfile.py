import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout
from conan.tools.files import copy
from conan.tools.build import can_run

class SupersortConan(ConanFile):
    name = 'super_sort'
    version = '0.0.1'

    license = 'MIT'
    author = 'Zach Laine'
    url = 'https://github.com/tzlaine/supersort'
    description = 'Sort things, but faster'
    topics = 'algorithm', 'sort', 'fast', 'super'
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'CMakeDeps'
    package_type = 'header-library'

    def export_sources(self):
        copy(self, "CMakeLists.txt", self.recipe_folder, self.export_sources_folder)
        copy(self, "include/*", self.recipe_folder, self.export_sources_folder)
        copy(self, "test/*", self.recipe_folder, self.export_sources_folder)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def layout(self):
        cmake_layout(self)

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ['super_sort']
