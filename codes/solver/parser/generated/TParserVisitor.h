
// Generated from TParser.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"
#include "TParser.h"


namespace antlrcpptest {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by TParser.
 */
class  TParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TParser.
   */
    virtual std::any visitCircuit(TParser::CircuitContext *context) = 0;

    virtual std::any visitElement(TParser::ElementContext *context) = 0;

    virtual std::any visitVoltagesource(TParser::VoltagesourceContext *context) = 0;

    virtual std::any visitCurrentsource(TParser::CurrentsourceContext *context) = 0;

    virtual std::any visitResistor(TParser::ResistorContext *context) = 0;

    virtual std::any visitCapacitor(TParser::CapacitorContext *context) = 0;

    virtual std::any visitInductor(TParser::InductorContext *context) = 0;


};

}  // namespace antlrcpptest
