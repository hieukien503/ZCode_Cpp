#ifndef MACHINE_CODE_HPP
#define MACHINE_CODE_HPP

#pragma once
#include "../../main.hpp"

namespace zcode {
    class JasminCode {
    public:
        static std::string END, INDENT;
    public:
        std::string emitPUSHNULL();
        std::string emitICONST(int num);
        std::string emitBIPUSH(int num);
        std::string emitSIPUSH(int num);
        std::string emitLDC(std::string val);
        std::string emitFCONST(std::string num);
        std::string emitILOAD(int i);
        std::string emitFLOAD(int i);
        std::string emitISTORE(int i);
        std::string emitFSTORE(int i);
        std::string emitALOAD(int i);
        std::string emitASTORE(int i);
        std::string emitIASTORE();
        std::string emitFASTORE();
        std::string emitBASTORE();
        std::string emitAASTORE();
        std::string emitIALOAD();
        std::string emitFALOAD();
        std::string emitBALOAD();
        std::string emitAALOAD();
        std::string emitGETSTATIC(std::string lexeme, std::string typ);
        std::string emitPUTSTATIC(std::string lexeme, std::string typ);
        std::string emitGETFIELD(std::string lexeme, std::string typ);
        std::string emitPUTFIELD(std::string lexeme, std::string typ);
        std::string emitIADD();
        std::string emitFADD();
        std::string emitISUB();
        std::string emitFSUB();
        std::string emitIMUL();
        std::string emitFMUL();
        std::string emitIDIV();
        std::string emitFDIV();
        std::string emitIREM();
        std::string emitFREM();
        std::string emitIAND();
        std::string emitIOR();
        std::string emitIFACMPEQ(int label);
        std::string emitIFACMPNE(int label);
        std::string emitIFICMPEQ(int label);
        std::string emitIFICMPNE(int label);
        std::string emitIFICMPLT(int label);
        std::string emitIFICMPLE(int label);
        std::string emitIFICMPGT(int label);
        std::string emitIFICMPGE(int label);
        std::string emitIFICMPGT(int label);
        std::string emitIFEQ(int label);
        std::string emitIFNE(int label);
        std::string emitIFLT(int label);
        std::string emitIFLE(int label);
        std::string emitIFGT(int label);
        std::string emitIFGE(int label);
        std::string emitLABEL(int label);
        std::string emitGOTO(int label);
        std::string emitINEG();
        std::string emitFNEG();
        std::string emitDUP();
        std::string emitDUPX2();
        std::string emitPOP();
        std::string emitI2F();
        std::string emitNEW(std::string lexeme);
        std::string emitNEWARRAY(std::string lexeme);
        std::string emitANEWARRAY(std::string lexeme);
        std::string emitMULTIANEWARRAY(std::string typ, int dimensions);
        std::string emitINVOKESTATIC(std::string lexeme, std::string typ);
        std::string emitINVOKESPECIAL(std::string lexeme = "", std::string typ = "");
        std::string emitINVOKEVIRTUAL(std::string lexeme, std::string typ);
        std::string emitI();
        std::string emitF();
        std::string emitLIMITSTACK(int i);
        std::string emitFCMPL();
        std::string emitLIMITLOCAL(int i);
        std::string emitVAR(int i, std::string varName, std::string inType, int fromLabel, int endLabel);
        std::string emitMETHOD(std::string lexeme, std::string typ, bool isStatic);
        std::string emitENDMETHOD();
        std::string emitSOURCE(std::string lexeme);
        std::string emitCLASS(std::string lexeme);
        std::string emitSUPER(std::string lexeme);
        std::string emitSTATICFIELD(std::string lexeme, std::string typ, bool isFinal);
        std::string emitINSTANCEFIELD(std::string lexeme, std::string typ);
        std::string emitRETURN();
        std::string emitIRETURN();
        std::string emitFRETURN();
        std::string emitARETURN();
    };
}

#endif