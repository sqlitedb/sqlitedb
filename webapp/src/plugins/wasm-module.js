import Module from "../../../nativium/build/wasm/release/wasm32/target/bin/nativium";
import { useWasmModuleStore } from "../stores/wasm-module";

export default {
    install: () => {
        Module().then((wasmModule) => {
            new Promise((r) => setTimeout(r, 300)).then(() => {
                const wm = useWasmModuleStore();
                wm.module = wasmModule;
                wm.setLoaded(true);
            });
        });
    },
};
