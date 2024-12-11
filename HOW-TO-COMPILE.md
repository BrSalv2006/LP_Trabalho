\page Como-Compilar Como Compilar
Se você optou por baixar o [**código fonte**](https://github.com/BrSalv2006/LP_Trabalho), siga as etapas abaixo para compilar o projeto:
- **Dependências:** 
  - Um compilador compatível com C (por exemplo, [GCC](https://gcc.gnu.org/))
  - [MAKE](https://www.gnu.org/software/make/) (OPCIONAL)

1. **Clonar o repositório:**
  ```bash
  git clone https://github.com/BrSalv2006/LP_Trabalho.git
  cd LP_Trabalho
  ```

2. **Compile o projeto (Apenas Compatível com [GCC](https://gcc.gnu.org/)):**
  - Opção 1 (Recomendado):\n
    Esta forma de compilação utiliza [MAKE](https://www.gnu.org/software/make/)
    ```bash
    make
    ```
  - Opção 2 (Manualmente):
    ```bash
    cc ./src/*.c -lm -o ./main.exe
    ```
  

4. **Execute o programa:**
  ```bash
  ./bin/main.exe
  ```