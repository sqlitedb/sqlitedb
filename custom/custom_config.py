import textwrap


# -----------------------------------------------------------------------------
def run(params):
    return [
        {
            "type": "remove-dir",
            "path": "modules/app-core",
        },
        {
            "type": "remove-dir",
            "path": "modules/app-main",
        },
        {
            "type": "remove-dir",
            "path": "modules/tests",
        },
        {
            "type": "symlink",
            "source": "modules/app-core",
            "target": "modules/app-core",
        },
        {
            "type": "symlink",
            "source": "modules/app-main",
            "target": "modules/app-main",
        },
        {
            "type": "symlink",
            "source": "modules/repository",
            "target": "modules/repository",
        },
        {
            "type": "copy-file",
            "source": "cmake/dependencies.cmake",
            "target": "cmake/dependencies.cmake",
        },
        {
            "type": "replace-text",
            "path": "targets/wasm/config/target_config.py",
            "list": [
                {
                    "old": 'has_debug = True',
                    "new": 'has_debug = False',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "targets/macos/config/target_config.py",
            "list": [
                {
                    "old": 'has_debug = True',
                    "new": 'has_debug = False',
                },
                {
                    "old": '"min_version": "10.9"',
                    "new": '"min_version": "10.15"',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "targets/windows/config/target_config.py",
            "list": [
                {
                    "old": 'has_debug = True',
                    "new": 'has_debug = False',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "targets/linux/config/target_config.py",
            "list": [
                {
                    "old": 'has_debug = True',
                    "new": 'has_debug = False',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "CMakeLists.txt",
            "list": [
                {
                    "old": 'set(NATIVIUM_C_FLAGS "-Wall" CACHE STRING "Custom C Flags")',
                    "new": textwrap.dedent("""\
                    if(NATIVIUM_TARGET STREQUAL "wasm")
                        set(NATIVIUM_C_FLAGS "-Wall -fwasm-exceptions" CACHE STRING "Custom C Flags")
                    else()
                        set(NATIVIUM_C_FLAGS "-Wall" CACHE STRING "Custom C Flags")
                    endif()
                    """)
                },
                {
                    "old": 'set(NATIVIUM_CXX_FLAGS "-Wall" CACHE STRING "Custom CXX Flags")',
                    "new": textwrap.dedent("""\
                    if(NATIVIUM_TARGET STREQUAL "wasm")
                        set(NATIVIUM_CXX_FLAGS "-Wall -fwasm-exceptions" CACHE STRING "Custom CXX Flags")
                    else()
                        set(NATIVIUM_CXX_FLAGS "-Wall" CACHE STRING "Custom CXX Flags")
                    endif()
                    """)
                },
                {
                    "old": 'set(NATIVIUM_WASM_LINK_FLAGS "--bind -s MALLOC=emmalloc -s WASM_BIGINT=1")',
                    "new": textwrap.dedent("""\
                    set(NATIVIUM_WASM_LINK_FLAGS "--bind -s MALLOC=emmalloc -s WASM_BIGINT=1 -fwasm-exceptions -sMODULARIZE -s EXPORT_ES6=1 -s EXPORTED_RUNTIME_METHODS=['FS']")"""),
                },
            ],
        },
    ]
