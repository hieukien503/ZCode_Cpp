#include "../headers/MachineCode.hpp"
#include "../headers/Exception.hpp"

namespace zcode {
    std::string JasminCode::END = "\n", JasminCode::INDENT = "\t";
    std::string JasminCode::emitPUSHNULL() {
        return JasminCode::INDENT + "aconst_null" + JasminCode::END;
    }

    std::string JasminCode::emitICONST(int i) {
        if (i == -1) return JasminCode::INDENT + "iconst_m1" + JasminCode::END;
        else if (i >= 0 and i <= 5) return JasminCode::INDENT + "iconst_" + std::to_string(i) + JasminCode::END;
        else throw IllegalOperandException(std::to_string(i));
    }

    std::string JasminCode::emitBIPUSH(int i) {
        if ((i >= -128 and i < -1) or (i > 5 and i <= 127)) return JasminCode::INDENT + "bipush " + std::to_string(i) + JasminCode::END;
        else throw IllegalOperandException(std::to_string(i));
    }

    std::string JasminCode::emitBIPUSH(int i) {
        if ((i >= -32768 and i < -128) or (i > 127 and i <= 32767)) return JasminCode::INDENT + "sipush " + std::to_string(i) + JasminCode::END;
        else throw IllegalOperandException(std::to_string(i));
    }

    std::string JasminCode::emitLDC(std::string i) {
        return JasminCode::INDENT + "ldc " + i + JasminCode::END;
    }

    std::string JasminCode::emitFCONST(std::string i) {
        if (i == "0.0") return JasminCode::INDENT + "fconst_0" + JasminCode::END;
        else if (i == "1.0") return JasminCode::INDENT + "fconst_1" + JasminCode::END;
        else if (i == "2.0") return JasminCode::INDENT + "fconst_2" + JasminCode::END;
        else throw IllegalOperandException(i);
    }

    std::string JasminCode::emitILOAD(int i) {
        if (i >= 0 and i <= 3) return JasminCode::INDENT + "iload_" + std::to_string(i) + JasminCode::END;
        return JasminCode::INDENT + "iload " + std::to_string(i) + JasminCode::END;
    }

    std::string JasminCode::emitFLOAD(int i) {
        if (i >= 0 and i <= 3) return JasminCode::INDENT + "fload_" + std::to_string(i) + JasminCode::END;
        return JasminCode::INDENT + "fload " + std::to_string(i) + JasminCode::END;
    }

    std::string JasminCode::emitISTORE(int i) {
        if (i >= 0 and i <= 3) return JasminCode::INDENT + "istore_" + std::to_string(i) + JasminCode::END;
        return JasminCode::INDENT + "istore " + std::to_string(i) + JasminCode::END;
    }

    std::string JasminCode::emitFSTORE(int i) {
        if (i >= 0 and i <= 3) return JasminCode::INDENT + "fstore_" + std::to_string(i) + JasminCode::END;
        return JasminCode::INDENT + "fstore " + std::to_string(i) + JasminCode::END;
    }

    std::string JasminCode::emitALOAD(int i) {
        if (i >= 0 and i <= 3) return JasminCode::INDENT + "aload_" + std::to_string(i) + JasminCode::END;
        return JasminCode::INDENT + "aload " + std::to_string(i) + JasminCode::END;
    }

    std::string JasminCode::emitASTORE(int i) {
        if (i >= 0 and i <= 3) return JasminCode::INDENT + "astore_" + std::to_string(i) + JasminCode::END;
        return JasminCode::INDENT + "astore " + std::to_string(i) + JasminCode::END;
    }

    std::string JasminCode::emitIASTORE() {
        return JasminCode::INDENT + "iastore" + JasminCode::END;
    }

    std::string JasminCode::emitFASTORE() {
        return JasminCode::INDENT + "fastore" + JasminCode::END;
    }

    std::string JasminCode::emitBASTORE() {
        return JasminCode::INDENT + "bastore" + JasminCode::END;
    }

    std::string JasminCode::emitAASTORE() {
        return JasminCode::INDENT + "aastore" + JasminCode::END;
    }

    std::string JasminCode::emitIASTORE() {
        return JasminCode::INDENT + "iaload" + JasminCode::END;
    }

    std::string JasminCode::emitFASTORE() {
        return JasminCode::INDENT + "faload" + JasminCode::END;
    }

    std::string JasminCode::emitBASTORE() {
        return JasminCode::INDENT + "baload" + JasminCode::END;
    }

    std::string JasminCode::emitAASTORE() {
        return JasminCode::INDENT + "aaload" + JasminCode::END;
    }

    std::string JasminCode::emitGETSTATIC(std::string lexeme, std::string typ) {
        return JasminCode::INDENT + "getstatic " + lexeme + " " + typ + JasminCode::END;
    }

    std::string JasminCode::emitPUTSTATIC(std::string lexeme, std::string typ) {
        return JasminCode::INDENT + "putstatic " + lexeme + " " + typ + JasminCode::END;
    }

    std::string JasminCode::emitGETFIELD(std::string lexeme, std::string typ) {
        return JasminCode::INDENT + "getfield " + lexeme + " " + typ + JasminCode::END;
    }

    std::string JasminCode::emitPUTFIELD(std::string lexeme, std::string typ) {
        return JasminCode::INDENT + "putfield " + lexeme + " " + typ + JasminCode::END;
    }

    std::string JasminCode::emitIADD() {
        return JasminCode::INDENT + "iadd" + JasminCode::END;
    }

    std::string JasminCode::emitFADD() {
        return JasminCode::INDENT + "fadd" + JasminCode::END;
    }

    std::string JasminCode::emitISUB() {
        return JasminCode::INDENT + "isub" + JasminCode::END;
    }

    std::string JasminCode::emitFSUB() {
        return JasminCode::INDENT + "fsub" + JasminCode::END;
    }

    std::string JasminCode::emitIMUL() {
        return JasminCode::INDENT + "imul" + JasminCode::END;
    }

    std::string JasminCode::emitFMUL() {
        return JasminCode::INDENT + "fmul" + JasminCode::END;
    }

    std::string JasminCode::emitIDIV() {
        return JasminCode::INDENT + "idiv" + JasminCode::END;
    }

    std::string JasminCode::emitFDIV() {
        return JasminCode::INDENT + "fdiv" + JasminCode::END;
    }

    std::string JasminCode::emitIREM() {
        return JasminCode::INDENT + "irem" + JasminCode::END;
    }

    std::string JasminCode::emitFREM() {
        return JasminCode::INDENT + "frem" + JasminCode::END;
    }

    std::string JasminCode::emitIAND() {
        return JasminCode::INDENT + "iand" + JasminCode::END;
    }

    std::string JasminCode::emitIOR() {
        return JasminCode::INDENT + "ior" + JasminCode::END;
    }

    std::string JasminCode::emitIFACMPEQ(int label) {
        return JasminCode::INDENT + "if_acmpeq Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFACMPNE(int label) {
        return JasminCode::INDENT + "if_acmpne Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFICMPEQ(int label) {
        return JasminCode::INDENT + "if_icmpeq Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFICMPNE(int label) {
        return JasminCode::INDENT + "if_icmpne Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFICMPLE(int label) {
        return JasminCode::INDENT + "if_icmple Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFICMPLT(int label) {
        return JasminCode::INDENT + "if_icmplt Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFICMPGE(int label) {
        return JasminCode::INDENT + "if_icmpge Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFICMPGT(int label) {
        return JasminCode::INDENT + "if_icmpgt Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFEQ(int label) {
        return JasminCode::INDENT + "if_eq Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFNE(int label) {
        return JasminCode::INDENT + "if_ne Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFLT(int label) {
        return JasminCode::INDENT + "if_lt Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFLE(int label) {
        return JasminCode::INDENT + "if_le Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFGT(int label) {
        return JasminCode::INDENT + "if_gt Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitIFGE(int label) {
        return JasminCode::INDENT + "if_ge Label " + std::to_string(label) + JasminCode::END;
    }

    std::string JasminCode::emitLABEL(int label) {
        return JasminCode::INDENT + "Label" + std::to_string(label) + ":" + JasminCode::END;
    }

    std::string JasminCode::emitINEG() {
        return JasminCode::INDENT + "ineg" + JasminCode::END;
    }

    std::string JasminCode::emitFNEG() {
        return JasminCode::INDENT + "fneg" + JasminCode::END;
    }

    std::string JasminCode::emitDUP() {
        return JasminCode::INDENT + "dup" + JasminCode::END;
    }

    std::string JasminCode::emitDUPX2() {
        return JasminCode::INDENT + "dup_x2" + JasminCode::END;
    }

    std::string JasminCode::emitPOP() {
        return JasminCode::INDENT + "pop" + JasminCode::END;
    }

    std::string JasminCode::emitI2F() {
        return JasminCode::INDENT + "i2f" + JasminCode::END;
    }

    std::string JasminCode::emitNEW(std::string lexeme) {
        return JasminCode::INDENT + "new " + lexeme + JasminCode::END;
    }

    std::string JasminCode::emitNEWARRAY(std::string lexeme) {
        return JasminCode::INDENT + "newarray " + lexeme + JasminCode::END;
    }

    std::string JasminCode::emitANEWARRAY(std::string lexeme) {
        return JasminCode::INDENT + "anewarray " + lexeme + JasminCode::END;
    }

    std::string JasminCode::emitMULTIANEWARRAY(std::string typ, int dimensions) {
        return JasminCode::INDENT + "multianewarray " + typ + " " + std::to_string(dimensions) + JasminCode::END;
    }

    std::string JasminCode::emitINVOKESTATIC(std::string lexeme, std::string typ) {
        return JasminCode::INDENT + "invokestatic " + lexeme + typ + JasminCode::END;
    }

    std::string JasminCode::emitINVOKESPECIAL(std::string lexeme, std::string typ) {
        if (lexeme == "" and typ == "") return JasminCode::INDENT + "invokespecial java/lang/Object/<init>()V" + JasminCode::END;
        return JasminCode::INDENT + "invokespecial " + lexeme + typ + JasminCode::END;
    }

    std::string JasminCode::emitINVOKEVIRTUAL(std::string lexeme, std::string typ) {
        return JasminCode::INDENT + "invokevirtual " + lexeme + typ + JasminCode::END;
    }

    std::string JasminCode::emitI() {
        return JasminCode::INDENT + "i" + JasminCode::END;
    }

    std::string JasminCode::emitF() {
        return JasminCode::INDENT + "i" + JasminCode::END;
    }

    std::string JasminCode::emitLIMITSTACK(int i) {
        return JasminCode::INDENT + ".limit stack " + std::to_string(i) + JasminCode::END;
    }

    std::string JasminCode::emitFCMPL() {
        return JasminCode::INDENT + "fcmpl" + JasminCode::END;
    }

    std::string JasminCode::emitLIMITLOCAL(int i) {
        return JasminCode::INDENT + ".limit locals " + std::to_string(i) + JasminCode::END;
    }

    std::string JasminCode::emitVAR(int i, std::string varName, std::string inType, int fromLabel, int endLabel) {
        return JasminCode::INDENT + ".var " + std::to_string(i) + " is " + varName + " " + inType + " from Label" + std::to_string(fromLabel) + " to Label" + std::to_string(endLabel)  + JasminCode::END;
    }

    std::string JasminCode::emitMETHOD(std::string lexeme, std::string typ, bool isStatic) {
        if (isStatic) return JasminCode::INDENT + ".method public static " + lexeme + typ + JasminCode::END;
        return JasminCode::INDENT + ".method public " + lexeme + typ + JasminCode::END;
    }

    std::string JasminCode::emitENDMETHOD() {
        return JasminCode::INDENT + ".end method" + JasminCode::END;
    }

    std::string JasminCode::emitSOURCE(std::string lexeme) {
        return JasminCode::INDENT + ".source " + lexeme + JasminCode::END;
    }

    std::string JasminCode::emitCLASS(std::string lexeme) {
        return JasminCode::INDENT + ".class " + lexeme + JasminCode::END;
    }

    std::string JasminCode::emitSUPER(std::string lexeme) {
        return JasminCode::INDENT + ".super " + lexeme + JasminCode::END;
    }

    std::string JasminCode::emitSTATICFIELD(std::string lexeme, std::string typ, bool isFinal) {
        if (isFinal) return JasminCode::INDENT + ".field static final " + lexeme + " " + typ + JasminCode::END;
        return JasminCode::INDENT + ".field static " + lexeme + " " + typ + JasminCode::END;
    }

    std::string JasminCode::emitINSTANCEFIELD(std::string lexeme, std::string typ) {
        return JasminCode::INDENT + ".field " + lexeme + " " + typ + JasminCode::END;
    }

    std::string JasminCode::emitIRETURN() {
        return JasminCode::INDENT + "ireturn" + JasminCode::END;
    }

    std::string JasminCode::emitFRETURN() {
        return JasminCode::INDENT + "freturn" + JasminCode::END;
    }

    std::string JasminCode::emitARETURN() {
        return JasminCode::INDENT + "areturn" + JasminCode::END;
    }

    std::string JasminCode::emitRETURN() {
        return JasminCode::INDENT + "return" + JasminCode::END;
    }
}