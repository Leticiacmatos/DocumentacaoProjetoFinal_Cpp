//!
//! \file           int0.hpp
//! \brief          External Interrupt INT0 peripheral control for the FunSAPE
//!                     AVR8 Library
//! \author         Leandro Schwarz (bladabuska+funsapeavr8lib@gmail.com)
//! \date           2023-05-07
//! \version        23.04
//! \copyright      license
//! \details        External Interrupt INT0 peripheral control for the FunSAPE
//!                     AVR8 Library
//! \todo           Todo list
//!

// =============================================================================
// Include guard (START)
// =============================================================================

#ifndef __INT0_HPP
#define __INT0_HPP                      2304

// =============================================================================
// Dependencies
// =============================================================================

//     /////////////////     GLOBAL DEFINITIONS FILE    /////////////////     //
#include "../globalDefines.hpp"
#if !defined(__GLOBAL_DEFINES_HPP)
#    error "Global definitions file is corrupted!"
#elif __GLOBAL_DEFINES_HPP != __INT0_HPP
#    error "Version mismatch between file header and global definitions file!"
#endif

//     //////////////////     LIBRARY DEPENDENCIES     //////////////////     //
#include "../util/debug.hpp"
#if !defined(__DEBUG_HPP)
#   error "Header file (debug.hpp) is corrupted!"
#elif __DEBUG_HPP != __INT0_HPP
#   error "Version mismatch between header file and library dependency (debug.hpp)!"
#endif

// =============================================================================
// Undefining previous definitions
// =============================================================================

// NONE

// =============================================================================
// Constant definitions
// =============================================================================

// NONE

// =============================================================================
// New data types
// =============================================================================

// NONE

// =============================================================================
// Interrupt callback functions
// =============================================================================

//!
//! \brief          INT0 interrupt callback function
//! \details        This function is called when the INT0 interrupt is treated.
//!                     It is a weak function that can be overwritten by user
//!                     code.
//!
void int0InterruptCallback();

// =============================================================================
// Int0 Class
// =============================================================================

//!
//! \brief          Int0 class
//! \details        Int0 class
//!
class Int0
{
    // -------------------------------------------------------------------------
    // New data types ----------------------------------------------------------
public:

    //     /////////////////     INT0 Trigger Sense     /////////////////     //
    //!
    //! \brief      Senso gatilho enumeração
    //! \details    Sense Trigger Events associados ao INT0.
    //! \warning    O valor associado aos nomes simbólicos pode mudar
    //!             entre construções e pode não refletir o registro/bits
    //!             valores reais.Para garantir a compatibilidade entre
    //!             construir, sempre se refere ao nome simbólico, em vez de
    //!             O valor que.
    //!
    enum class SenseMode : uint8_t {
        LOW_LEVEL           = 0,    //!< Gatilho interrompe continuamente enquanto o pino está em nível baixo lógico
        BOTH_EDGES          = 1,    //!< Gatilho interrompe nas duas bordas
        FALLING_EDGE        = 2,    //!< Gatilho interrompe na borda descida
        RISING_EDGE         = 3,    //!< Gatilho de interrupção de interrupção borda
    };

    // -------------------------------------------------------------------------
    // Constructors ------------------------------------------------------------
public:

    //!
    //! \brief      Construtor de classe INT0
    //! \details    Cria um objeto int0
    //!
    Int0(void);

    //!
    //! \brief      Int0 Class Destructor
    //! \details    Destrói um objeto INT0
    //!
    ~Int0(void);

    // -------------------------------------------------------------------------
    // Methods -----------------------------------------------------------------
public:
    //     ///////////////////     INITIALIZATION    ////////////////////     //

    //!
    //! \brief      Inicializa o módulo INT0
    //! \details    Inicializa o módulo INT0.
    //! \param      senseMode_p         Gatilho senso
    //! \return     bool_t              verdadeiroOnSuccess /falsoOnFailure
    //!
    bool_t init(SenseMode senseMode_p);

    //!
    //! \brief      Configures the trigger sense mode
    //! \details    Configures the trigger sense mode.
    //! \param      senseMode_p         Trigger sense mode
    //! \return     bool_t              True on success / False on failure
    //!
    bool_t setSenseMode(SenseMode senseMode_p);

    //     /////////////////     CONTROL AND STATUS    //////////////////     //

    //!
    //! \brief      Returns the last error
    //! \details    Returns the last error.
    //! \return     Error               Error status of the last operation
    //!
    Error           getLastError(
            void
    );

    //     //////////////////////    INTERRUPT     //////////////////////     //

    //!
    //! \brief      Activates interrupt
    //! \details    Activates interrupt.
    //!
    void inlined activateInterrupt(
            void
    );

    //!
    //! \brief      Clears interrupt flag
    //! \details    Clears interrupt flag.
    //!
    void inlined clearInterruptRequest(
            void
    );

    //!
    //! \brief      Deactivates interrupt
    //! \details    Deactivates interrupt.
    //!
    void inlined deactivateInterrupt(
            void
    );

    // -------------------------------------------------------------------------
    // Properties --------------------------------------------------------------
private:
    bool_t          _isInitialized      : 1;
    SenseMode       _senseMode;
    Error           _lastError;
}; // class Int0

// =============================================================================
// Inlined class functions
// =============================================================================

//     ////////////////////////    INTERRUPT     ////////////////////////     //
void inlined Int0::activateInterrupt(void)
{
    setBit(EIMSK, INT0);
    return;
}

void inlined Int0::clearInterruptRequest(void)
{
    setBit(EIFR, INTF0);
    return;
}

void inlined Int0::deactivateInterrupt(void)
{
    clrBit(EIMSK, INT0);
    return;
}

// =============================================================================
// External global variables
// =============================================================================

//!
//! \brief          Int0 peripheral handler object
//! \details        Int0 peripheral handler object
//!
extern Int0 int0;

// =============================================================================
// Include guard (END)
// =============================================================================

#endif  // __INT0_HPP

// =============================================================================
// END OF FILE
// =============================================================================
