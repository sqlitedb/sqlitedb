import { fileURLToPath, URL } from "url";

import { quasar, transformAssetUrls } from "@quasar/vite-plugin";
import vue from "@vitejs/plugin-vue";
import { defineConfig } from "vite";
import EnvironmentPlugin from "vite-plugin-environment";

// https://vitejs.dev/config/
export default defineConfig({
    plugins: [
        vue({
            template: { transformAssetUrls },
        }),
        quasar({
            sassVariables: "src/quasar-variables.sass",
        }),
        EnvironmentPlugin(
            {
                CURRENT_DATE_TIME:
                    new Date().toJSON().slice(0, 19).replace("T", " ") + " UTC",
            },
            {
                defineOn: "import.meta.env",
            }
        ),
    ],
    resolve: {
        alias: {
            "@": fileURLToPath(new URL("./src", import.meta.url)),
        },
    },
    build: {
        target: ["esnext"],
    },
    server: {
        fs: {
            allow: [".."],
        },
    },
});
