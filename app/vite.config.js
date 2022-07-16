import { fileURLToPath, URL } from "url";

import { quasar, transformAssetUrls } from "@quasar/vite-plugin";
import vue from "@vitejs/plugin-vue";
import { defineConfig } from "vite";

// https://vitejs.dev/config/
export default defineConfig({
    plugins: [
        vue({
            template: { transformAssetUrls },
        }),
        quasar({
            sassVariables: "src/quasar-variables.sass",
        }),
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
