## ESP-IDF Komponenty

Pro integraci jedné komponenty z knihovny `esp-idf-lib` do vašeho PlatformIO projektu postupujte podle následujících kroků:

1. **Najděte Komponentu**:
    - Nejprve najděte komponentu z `esp-idf-lib`, kterou chcete použít, na GitHubu nebo na oficiální stránce knihovny.

2. **Klonujte nebo Stáhněte Knihovnu**:
    - Klonujte celou knihovnu `esp-idf-lib` nebo si stáhněte pouze požadovanou komponentu. Pro klonování celé knihovny použijte git příkaz:
      ```
      git clone https://github.com/UncleRus/esp-idf-lib.git
      ```
    - Pokud chcete pouze jednu komponentu, můžete si stáhnout pouze relevantní soubory této komponenty.

3. **Přidejte Komponentu do Vašeho Projektu**:
    - Zkopírujte složku komponenty do složky `components` ve vašem PlatformIO projektu. Pokud složka `components` neexistuje, vytvořte ji.

4. **Aktualizujte `CMakeLists.txt` nebo `component.mk`**:
    - Pokud vaše komponenta obsahuje `CMakeLists.txt` (pro ESP-IDF 4.x) nebo `component.mk` (pro starší verze ESP-IDF), ujistěte se, že jsou v složce komponenty.
    - Pro ESP-IDF 4.x a novější: `CMakeLists.txt` by měl být již součástí komponenty. Ujistěte se, že soubor existuje a je správně nastaven.

5. **Upravte `platformio.ini`**:
    - Přidejte cestu k vaší komponentě do `platformio.ini` souboru vašeho projektu pomocí `lib_extra_dirs` nebo `build_flags`. Například:
      ```ini
      [env:myenv]
      platform = espressif32
      board = esp32dev
      framework = espidf
      lib_extra_dirs = components
      ```

6. **Použití Komponenty ve Vašem Kódu**:
    - Nyní můžete importovat a používat komponentu ve vašem hlavním zdrojovém souboru nebo kdekoli ve vašem projektu.

7. **Kompilace a Testování**:
    - Po dokončení těchto kroků zkompilujte váš projekt a ověřte, že komponenta funguje podle očekávání.

Pamatujte, že některé komponenty mohou vyžadovat specifická nastavení nebo závislosti. Vždy se podívejte na dokumentaci nebo README soubor komponenty pro specifické instrukce.

## Příklad Struktury Projektu
```
MyProject/
│
├── .pio/                      # Složka generovaná PlatformIO, obsahuje build soubory a konfigurace
│
├── components/                # Složka pro externí komponenty ESP-IDF
│   └── my_component/          # Složka pro vámi zvolenou komponentu z esp-idf-lib
│       ├── CMakeLists.txt     # CMake konfigurační soubor pro komponentu (pro ESP-IDF 4.x)
│       ├── component.mk       # Makefile pro komponentu (pro starší verze ESP-IDF)
│       └── ...                # Další soubory komponenty (zdrojové kódy, hlavičkové soubory atd.)
│
├── include/                   # Hlavičkové soubory
```

## Resources
- https://github.com/espressif/esp-idf
- https://github.com/UncleRus/esp-idf-lib
- https://github.com/nopnop2002/esp-idf-ssd1306

## MenuConfig nastavení
```sh
pio run -t menuconfig
```