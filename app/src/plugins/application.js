import { useRepositoryStore } from "../stores/repository";

export default {
    install: (app) => {
        app.provide("Application", {
            reset() {
                const repository = useRepositoryStore();
                repository.reset();

                app.config.globalProperties.$WM.Repository.shared().close();
            },
        });
    },
};
