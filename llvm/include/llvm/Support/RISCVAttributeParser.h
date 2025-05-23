//===-- RISCVAttributeParser.h - RISCV Attribute Parser ---------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_SUPPORT_RISCVATTRIBUTEPARSER_H
#define LLVM_SUPPORT_RISCVATTRIBUTEPARSER_H

#include "llvm/Support/Compiler.h"
#include "llvm/Support/ELFAttrParserCompact.h"
#include "llvm/Support/RISCVAttributes.h"

namespace llvm {
class LLVM_ABI RISCVAttributeParser : public ELFCompactAttrParser {
  struct DisplayHandler {
    RISCVAttrs::AttrType attribute;
    Error (RISCVAttributeParser::*routine)(unsigned);
  };
  static const DisplayHandler displayRoutines[];

  Error handler(uint64_t tag, bool &handled) override;

  Error unalignedAccess(unsigned tag);
  Error stackAlign(unsigned tag);
  Error atomicAbi(unsigned tag);

public:
  RISCVAttributeParser(ScopedPrinter *sw)
      : ELFCompactAttrParser(sw, RISCVAttrs::getRISCVAttributeTags(), "riscv") {
  }
  RISCVAttributeParser()
      : ELFCompactAttrParser(RISCVAttrs::getRISCVAttributeTags(), "riscv") {}
};

} // namespace llvm

#endif
