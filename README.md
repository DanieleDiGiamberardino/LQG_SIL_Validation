# LQG_SIL_Validation
Software-in-the-Loop (SIL) validation framework for an LQG controller, designed for embedded deployment.

## Overview
This project demonstrates the validation of a control algorithm (LQG) extracted from Simulink. It validates the determinism and precision of the C-generated code by implementing a data-injection pipeline in a native Linux environment (WSL).

## Key Features
- **Code Decoupling:** Removal of proprietary Simulink logging dependencies.
- **Native Compilation:** GCC-based compilation of control kernels.
- **Data Injection:** Verification of discretization accuracy by comparing C-generated outputs against MATLAB ground-truth data.

## Results
The validation shows a perfect match (0 error) between the Simulink solver and the generated C code, confirming the algorithm is production-ready.
![Validation Plot](docs/sil_validation_plot.png)
