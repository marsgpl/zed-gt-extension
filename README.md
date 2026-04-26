# gt

this is a zed editor extension to highlight syntax for custom text file "gt". zed must build it automatically: no source code generation or compilation is needed in this repo.

## release

```sh
npm run release
```

then reload extension in zed

## error indication

add this to ~/.config/zed/settings.json:

```json
"experimental.theme_overrides": {
    "syntax": {
        "variant": {
            "color": "#ffffff",
            "background_color": "#cc0000"
        }
    }
}
```
