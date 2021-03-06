/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2013 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_AWAIT_EXPRESSION_H_
#define incl_HPHP_AWAIT_EXPRESSION_H_

#include "hphp/compiler/expression/expression.h"
#include "hphp/compiler/expression/generation_label.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

DECLARE_BOOST_TYPES(AwaitExpression);

class AwaitExpression : public Expression {
public:
  AwaitExpression(EXPRESSION_CONSTRUCTOR_PARAMETERS,
                  ExpressionPtr exp);

  DECLARE_EXPRESSION_VIRTUAL_FUNCTIONS;

  ExpressionPtr getExpression() { return m_exp; }
  GenerationLabel& label() { return m_label; }

private:
  ExpressionPtr m_exp;
  GenerationLabel m_label;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_AWAIT_EXPRESSION_H_
