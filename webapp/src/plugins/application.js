import { useRepositoryStore } from "../stores/repository";
import { useWasmModuleStore } from "../stores/wasm-module";

export default {
    install: (app) => {
        app.provide("Application", {
            reset() {
                const repository = useRepositoryStore();
                repository.reset();

                const wm = useWasmModuleStore();
                wm.module.Repository.shared().close();
            },
        });
    },
};
