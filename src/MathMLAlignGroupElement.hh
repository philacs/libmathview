// Copyright (C) 2000, Luca Padovani <luca.padovani@cs.unibo.it>.
// 
// This file is part of GtkMathView, a Gtk widget for MathML.
// 
// GtkMathView is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// GtkMathView is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GtkMathView; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
// 
// For details, see the GtkMathView World-Wide-Web page,
// http://cs.unibo.it/~lpadovan/mml-widget, or send a mail to
// <luca.padovani@cs.unibo.it>

#ifndef MathMLAlignGroupElement_hh
#define MathMLAlignGroupElement_hh

#if defined(HAVE_GMETADOM)
#include "gmetadom.hh"
#endif

#include "MathMLElement.hh"

class MathMLAlignGroupElement: public MathMLElement
{
protected:
  MathMLAlignGroupElement(void);
#if defined(HAVE_GMETADOM)
  MathMLAlignGroupElement(const DOM::Element&);
#endif
  virtual ~MathMLAlignGroupElement();
private:
  void Init(void);

public:
  static SmartPtr<MathMLElement> create(void)
  { return SmartPtr<MathMLElement>(new MathMLAlignGroupElement()); }
#if defined(HAVE_GMETADOM)
  static SmartPtr<MathMLElement> create(const DOM::Element& el)
  { return SmartPtr<MathMLElement>(new MathMLAlignGroupElement(el)); }
#endif

  virtual void DoLayout(const class FormattingContext&);

  void SetWidth(const scaled&);
  void SetDecimalPoint(const SmartPtr<class MathMLTokenElement>&);
  void SetAlignmentMark(const SmartPtr<class MathMLMarkNode>&);
  void SetAlignmentMark(const SmartPtr<class MathMLAlignMarkElement>&);

  const SmartPtr<class MathMLMarkNode>& GetAlignmentMarkNode(void) const { return alignMarkNode; }
  const SmartPtr<class MathMLAlignMarkElement>& GetAlignmentMarkElement(void) const { return alignMarkElement; }
  const SmartPtr<class MathMLTokenElement>& GetDecimalPoint(void) const { return decimalPoint; }

  virtual void Normalize(const SmartPtr<class MathMLDocument>&);
  virtual bool IsSpaceLike(void) const;

private:
  scaled width;

  SmartPtr<class MathMLMarkNode>         alignMarkNode;
  SmartPtr<class MathMLAlignMarkElement> alignMarkElement;
  SmartPtr<class MathMLTokenElement>     decimalPoint;
};

#endif // MathMLAlignGroupElement_hh
