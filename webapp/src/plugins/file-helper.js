import { useRepositoryStore } from "../stores/repository";
import { useWasmModuleStore } from "../stores/wasm-module";

export default {
    install: (app) => {
        app.provide("FileHelper", {
            openLocalFile(onSuccess, onLoading, onError) {
                var input = document.createElement("input");
                input.type = "file";

                input.onchange = async (e) => {
                    try {
                        // start loading
                        onLoading();

                        // module
                        const wm = useWasmModuleStore();

                        // file reference
                        var file = e.target.files[0];

                        // read file bytes
                        let fileByteArray = await this.fileToByteArray(file);

                        if (fileByteArray.length <= 0) {
                            onError({
                                message: "The database file is invalid",
                            });
                            return;
                        }

                        let data = new Uint8Array(fileByteArray);

                        // store the file on virtual file system
                        let filename = "sqlitedb.db";
                        let stream = wm.module.FS.open(filename, "w+");
                        wm.module.FS.write(stream, data, 0, data.length, 0);
                        wm.module.FS.close(stream);

                        // open
                        wm.module.Repository.shared().open(filename);

                        // store info
                        const repository = useRepositoryStore();
                        repository.setInfo(
                            wm.module.Repository.shared().getInfo()
                        );
                        repository.setLoaded(true);

                        onSuccess();
                    } catch (error) {
                        onError({ message: error });
                        return;
                    }
                };

                input.click();
            },

            async openFromRemoteFile(file, onSuccess, onLoading, onError) {
                try {
                    // start loading
                    onLoading();

                    // module
                    const wm = useWasmModuleStore();

                    // load remote file
                    let response = await fetch(file);
                    let fileBuffer = await response.arrayBuffer();

                    // read file bytes
                    let fileByteArray = new Uint8Array(fileBuffer);

                    if (fileByteArray.length <= 0) {
                        onError({
                            message: "The database file is invalid",
                        });
                        return;
                    }

                    let data = new Uint8Array(fileByteArray);

                    // store the file on virtual file system
                    let filename = "sqlitedb.db";
                    let stream = wm.module.FS.open(filename, "w+");
                    wm.module.FS.write(stream, data, 0, data.length, 0);
                    wm.module.FS.close(stream);

                    // open
                    wm.module.Repository.shared().open(filename);

                    // store info
                    const repository = useRepositoryStore();
                    repository.setInfo(wm.module.Repository.shared().getInfo());
                    repository.setLoaded(true);

                    onSuccess();
                } catch (error) {
                    onError({ message: error });
                    return;
                }
            },

            fileToByteArray(file) {
                return new Promise((resolve, reject) => {
                    try {
                        // create file reader
                        let reader = new FileReader();

                        // register event listeners
                        reader.addEventListener("loadend", (e) =>
                            resolve(e.target.result)
                        );

                        reader.addEventListener("error", reject);

                        // read file
                        reader.readAsArrayBuffer(file);
                    } catch (e) {
                        reject(e);
                    }
                });
            },
        });
    },
};
