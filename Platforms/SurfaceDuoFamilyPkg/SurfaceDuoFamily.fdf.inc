#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014-2016, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2017, Intel Corporation. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#

################################################################################
#
# Rules are use with the [FV] section's module INF type to define
# how an FFS file is created for a given INF file. The following Rule are the default
# rules for the different module type. User can add the customized rules to define the
# content of the FFS file.
#
################################################################################


############################################################################
# Example of a DXE_DRIVER FFS file with a Checksum encapsulation section   #
############################################################################
#
#[Rule.Common.DXE_DRIVER]
#  FILE DRIVER = $(NAMED_GUID) {
#    DXE_DEPEX    DXE_DEPEX               Optional $(INF_OUTPUT)/$(MODULE_NAME).depex
#    COMPRESS PI_STD {
#      GUIDED {
#        PE32     PE32                    $(INF_OUTPUT)/$(MODULE_NAME).efi
#        UI       STRING="$(MODULE_NAME)" Optional
#        VERSION  STRING="$(INF_VERSION)" Optional BUILD_NUM=$(BUILD_NUMBER)
#      }
#    }
#  }
#
############################################################################

[Rule.Common.SEC]
  FILE SEC = $(NAMED_GUID) RELOCS_STRIPPED FIXED {
    TE  TE Align = Auto                 $(INF_OUTPUT)/$(MODULE_NAME).efi
  }

[Rule.Common.PEI_CORE]
  FILE PEI_CORE = $(NAMED_GUID) FIXED {
    TE     TE Align = Auto              $(INF_OUTPUT)/$(MODULE_NAME).efi
    UI     STRING ="$(MODULE_NAME)" Optional
  }

[Rule.Common.PEIM]
  FILE PEIM = $(NAMED_GUID) FIXED {
     PEI_DEPEX PEI_DEPEX Optional       $(INF_OUTPUT)/$(MODULE_NAME).depex
     TE       TE Align = Auto           $(INF_OUTPUT)/$(MODULE_NAME).efi
     UI       STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.PEIM.TIANOCOMPRESSED]
  FILE PEIM = $(NAMED_GUID) DEBUG_MYTOOLS_IA32 {
    PEI_DEPEX PEI_DEPEX Optional        $(INF_OUTPUT)/$(MODULE_NAME).depex
    GUIDED A31280AD-481E-41B6-95E8-127F4C984779 PROCESSING_REQUIRED = TRUE {
      PE32      PE32                    $(INF_OUTPUT)/$(MODULE_NAME).efi
      UI        STRING="$(MODULE_NAME)" Optional
    }
  }

[Rule.Common.DXE_CORE]
  FILE DXE_CORE = $(NAMED_GUID) {
    PE32     PE32                       $(INF_OUTPUT)/$(MODULE_NAME).efi
    UI       STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.UEFI_DRIVER]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX    DXE_DEPEX              Optional $(INF_OUTPUT)/$(MODULE_NAME).depex
    PE32         PE32                   $(INF_OUTPUT)/$(MODULE_NAME).efi
    UI           STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.DXE_DRIVER]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX    DXE_DEPEX              Optional $(INF_OUTPUT)/$(MODULE_NAME).depex
    PE32         PE32                   $(INF_OUTPUT)/$(MODULE_NAME).efi
    UI           STRING="$(MODULE_NAME)" Optional
    RAW          ACPI  Optional               |.acpi
    RAW          ASL   Optional               |.aml
  }

[Rule.Common.DXE_DRIVER.BINARY]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX    DXE_DEPEX Optional      |.depex
    PE32         PE32                    |.efi
    UI           STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.DXE_RUNTIME_DRIVER]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX    DXE_DEPEX              Optional $(INF_OUTPUT)/$(MODULE_NAME).depex
    PE32         PE32                   $(INF_OUTPUT)/$(MODULE_NAME).efi
    UI           STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.DXE_RUNTIME_DRIVER.BINARY]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX    DXE_DEPEX Optional      |.depex
    PE32         PE32                    |.efi
    UI           STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.UEFI_APPLICATION]
  FILE APPLICATION = $(NAMED_GUID) {
    UI     STRING ="$(MODULE_NAME)"     Optional
    PE32   PE32                         $(INF_OUTPUT)/$(MODULE_NAME).efi
  }

[Rule.Common.UEFI_DRIVER.BINARY]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX DXE_DEPEX Optional      |.depex
    PE32      PE32                    |.efi
    UI        STRING="$(MODULE_NAME)" Optional
    VERSION   STRING="$(INF_VERSION)" Optional BUILD_NUM=$(BUILD_NUMBER)
  }

[Rule.Common.UEFI_APPLICATION.BINARY]
  FILE APPLICATION = $(NAMED_GUID) {
    PE32      PE32                    |.efi
    UI        STRING="$(MODULE_NAME)" Optional
    VERSION   STRING="$(INF_VERSION)" Optional BUILD_NUM=$(BUILD_NUMBER)
  }

[Rule.Common.USER_DEFINED.ACPITABLE]
  FILE FREEFORM = $(NAMED_GUID) {
    RAW       ACPI                    |.acpi
    RAW       ASL                     |.aml
    UI        STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.MM_CORE_STANDALONE]
  FILE SEC = $(NAMED_GUID) RELOCS_STRIPPED FIXED {
    PE32  PE32 Align = Auto             $(INF_OUTPUT)/$(MODULE_NAME).efi
  }

[Rule.Common.PEIM.BINARY]
  FILE PEIM = $(NAMED_GUID) {
    PEI_DEPEX PEI_DEPEX Optional      |.depex
    PE32      PE32     Align = Auto   |.efi
    UI        STRING="$(MODULE_NAME)" Optional
    VERSION   STRING="$(INF_VERSION)" Optional BUILD_NUM=$(BUILD_NUMBER)
  }

[Rule.Common.DXE_DRIVER.BINARY]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX DXE_DEPEX Optional      |.depex
    PE32      PE32                    |.efi
    UI        STRING="$(MODULE_NAME)" Optional
    VERSION   STRING="$(INF_VERSION)" Optional BUILD_NUM=$(BUILD_NUMBER)
  }

[Rule.Common.MM_STANDALONE]
  FILE MM_STANDALONE = $(NAMED_GUID) {
    SMM_DEPEX SMM_DEPEX Optional       $(INF_OUTPUT)/$(MODULE_NAME).depex
    PE32      PE32                     $(INF_OUTPUT)/$(MODULE_NAME).efi
    UI        STRING="$(MODULE_NAME)" Optional
    VERSION   STRING="$(INF_VERSION)" Optional BUILD_NUM=$(BUILD_NUMBER)
  }

[Rule.Common.MM_STANDALONE.BINARY]
 FILE MM_STANDALONE = $(NAMED_GUID) {
   SMM_DEPEX SMM_DEPEX Optional      |.depex
   PE32      PE32                    |.efi
   UI        STRING="$(MODULE_NAME)" Optional
   VERSION   STRING="$(INF_VERSION)" Optional BUILD_NUM=$(BUILD_NUMBER)
  }