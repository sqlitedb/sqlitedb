import Module from "../../../nativium/build/wasm/release/wasm/target/bin/nativium";
import EventBus from "../classes/event-bus";
import { useWasmModuleStore } from "../stores/wasm-module";

export default {
    install: (app) => {
        Module().then((wasmModule) => {
            new Promise((r) => setTimeout(r, 300)).then(() => {
                // TODO: What is the best place to store WASM module globally?
                // Because it need by access from non Vue classes (ex: DatabaseItem)
                app.config.globalProperties.$WM = wasmModule;
                window.WM = wasmModule;

                const wm = useWasmModuleStore();
                wm.setLoaded(true);

                EventBus.$emit("wasm-module-loaded");
            });
        });
    },
};
