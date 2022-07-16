import Module from "../../../nativium/build/wasm/release/wasm/target/bin/nativium";
import EventBus from "../classes/event-bus";
import { useWasmModuleStore } from "../stores/wasm-module";

export default {
    install: (app) => {
        Module().then((wasmModule) => {
            new Promise((r) => setTimeout(r, 300)).then(() => {
                app.config.globalProperties.$WM = wasmModule;

                const wm = useWasmModuleStore();
                wm.setLoaded(true);

                EventBus.$emit("wasm-module-loaded");
            });
        });
    },
};
