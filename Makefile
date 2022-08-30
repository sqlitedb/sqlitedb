ROOT_DIR=${PWD}

.DEFAULT_GOAL := help
.PHONY: build nativium

# tasks
help:
	@echo "Type: make [rule]. Available options are:"
	@echo ""
	@echo "- help"
	@echo "- clean"
	@echo "- nativium"
	@echo "- custom-install"
	@echo "- format"
	@echo "- gluecode"
	@echo ""
	@echo "- build-macos"
	@echo "- build-linux"
	@echo "- build-windows"
	@echo "- build-wasm"
	@echo "- build-ios"
	@echo "- build-android"
	@echo ""
	@echo "- run-macos"
	@echo "- run-linux"
	@echo "- run-windows"
	@echo "- run-wasm"

clean:
	@echo "Cleaning..."
	@rm -rf nativium
	@rm -rf .DS_Store
	@rm -rf *.pyc
	@rm -rf Thumbs.db
	@echo "OK"

nativium:
	@rm -rf nativium
	@git clone https://github.com/nativium/nativium.git nativium

custom-install:
	@cd nativium && python3 nativium.py custom install --path=${ROOT_DIR}/custom

build-macos:
	@make custom-install
	@cd nativium && python3 nativium.py target macos setup
	@cd nativium && python3 nativium.py target macos build
	@cd nativium && python3 nativium.py target macos package

build-linux:
	@make custom-install
	@cd nativium && python3 nativium.py target linux setup
	@cd nativium && python3 nativium.py target linux build
	@cd nativium && python3 nativium.py target linux package

build-windows:
	@make custom-install
	@cd nativium && python3 nativium.py target windows setup
	@cd nativium && python3 nativium.py target windows build
	@cd nativium && python3 nativium.py target windows package

build-wasm:
	@make custom-install
	@cd nativium && python3 nativium.py target wasm setup
	@cd nativium && python3 nativium.py target wasm build
	@cd nativium && python3 nativium.py target wasm package

build-ios:
	@make custom-install
	@cd nativium && python3 nativium.py target ios setup
	@cd nativium && python3 nativium.py target ios build
	@cd nativium && python3 nativium.py target ios package --no-framework
	@cd nativium && python3 nativium.py app ios pods
	@cd nativium && python3 nativium.py app ios build

build-android:
	@make custom-install
	@cd nativium && python3 nativium.py target android setup
	@cd nativium && python3 nativium.py target android build
	@cd nativium && python3 nativium.py target android package
	@cd nativium && python3 nativium.py app android build

run-macos:
	@cd nativium && python3 nativium.py target macos run --build=release

run-linux:
	@cd nativium && python3 nativium.py target linux run --build=release

run-windows:
	@cd nativium && python3 nativium.py target windows run --build=release

run-wasm:
	@cd nativium && python3 nativium.py target wasm serve --build=release

format:
	@cd nativium && python3 nativium.py code format --path=../custom

gluecode:
	@make custom-install
	@cd nativium && python3 nativium.py gluecode setup
	@cd nativium && python3 nativium.py gluecode generate
