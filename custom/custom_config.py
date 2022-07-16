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
            "path": "core/const.py",
            "list": [
                {
                    "old": 'BUCKET_NAME = "nativium"',
                    "new": 'BUCKET_NAME = "sqlite-viewer"',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "targets/wasm/config/target.py",
            "list": [
                {
                    "old": '["debug", "release"]',
                    "new": '["release"]',
                },
                {
                    "old": '"append_version": True',
                    "new": '"append_version": False',
                },
                {
                    "old": '"url": "https://nativium.s3.amazonaws.com/demo"',
                    "new": '"url": "https://sqlite-viewer.s3.amazonaws.com/app"',
                },
                {
                    "old": '"publish_bucket_name": "nativium"',
                    "new": '"publish_bucket_name": "sqlite-viewer"',
                },
                {
                    "old": '"publish_bucket_path": "demo"',
                    "new": '"publish_bucket_path": "app"',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "targets/macos/config/target.py",
            "list": [
                {
                    "old": '["debug", "release"]',
                    "new": '["release"]',
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
                    "old": '["debug", "release"]',
                    "new": '["release"]',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "targets/linux/config/target.py",
            "list": [
                {
                    "old": '["debug", "release"]',
                    "new": '["release"]',
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
