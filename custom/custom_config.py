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
            "type": "replace-text",
            "path": "targets/wasm/config/target.py",
            "list": [
                {
                    "old": 'has_debug = True',
                    "new": 'has_debug = False',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "targets/macos/config/target.py",
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
            "path": "targets/windows/config/target.py",
            "list": [
                {
                    "old": 'has_debug = True',
                    "new": 'has_debug = False',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "targets/linux/config/target.py",
            "list": [
                {
                    "old": 'has_debug = True',
                    "new": 'has_debug = False',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "targets/wasm/cmake/target.cmake",
            "list": [
                {
                    "old": 'set(NATIVIUM_WASM_C_FLAGS "")',
                    "new": 'set(NATIVIUM_WASM_C_FLAGS "-fwasm-exceptions")',
                },
                {
                    "old": 'set(NATIVIUM_WASM_CXX_FLAGS "")',
                    "new": 'set(NATIVIUM_WASM_CXX_FLAGS "-fwasm-exceptions")',
                },
                {
                    "old": '"--bind -s MALLOC=emmalloc -s WASM_BIGINT=1"',
                    "new": "\"--bind -s MALLOC=emmalloc -s WASM_BIGINT=1 -fwasm-exceptions -sMODULARIZE -s EXPORT_ES6=1 -s EXPORTED_RUNTIME_METHODS=['FS']\"",
                },
            ],
        },
    ]
