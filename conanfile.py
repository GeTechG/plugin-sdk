from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class ldyomRecipe(ConanFile):
    name = "plugin"
    version = "0.0"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = (
        "CMake/*", "CMakeLists.txt",
        "plugin_sa/*",
        "shared/*",
        "stb/*",
        "hooking/*",
        "injector/*",
        "safetyhook/*",
        "modutils/*",
    )


    def config_options(self):
        pass

    def configure(self):
        pass

    def layout(self):
        cmake_layout(self)
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()
    
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
    
    def package(self):
        cmake = CMake(self)
        cmake.install()
    
    def package_info(self):
        self.cpp_info.set_property("cmake_file_name", "plugin")
        self.cpp_info.set_property("cmake_target_name", "plugin::plugin_sa")

        self.cpp_info.filenames["cmake_find_package"] = "plugin"
        self.cpp_info.filenames["cmake_find_package_multi"] = "plugin"
        self.cpp_info.names["cmake_find_package"] = "plugin"
        self.cpp_info.names["cmake_find_package_multi"] = "plugin"
        
        if self.settings.build_type == "Debug":
            self.cpp_info.libs = ["plugin_d"]
        else:
            self.cpp_info.libs = ["plugin"]
        
        self.cpp_info.includedirs = [
            "include",
            "include/game_sa",
            "include/game_sa/rw",
            "include/shared",
            "include/shared/game",
            "include/safetyhook"
        ]
