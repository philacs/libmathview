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

#ifndef MathMLStyleElement_hh
#define MathMLStyleElement_hh

#if defined(HAVE_GMETADOM)
#include "gmetadom.hh"
#endif

#include "MathMLEmbellishment.hh"
#include "MathMLNormalizingContainerElement.hh"

class MathMLStyleElement
  : public MathMLNormalizingContainerElement, public MathMLEmbellishment
{
public:
  MathMLStyleElement(void);
#if defined(HAVE_GMETADOM)
  MathMLStyleElement(const DOM::Element&);
#endif
  virtual ~MathMLStyleElement();

public:
  static SmartPtr<MathMLElement> create(void)
  { return SmartPtr<MathMLElement>(new MathMLStyleElement()); }
#if defined(HAVE_GMETADOM)
  static SmartPtr<MathMLElement> create(const DOM::Element& el)
  { return SmartPtr<MathMLElement>(new MathMLStyleElement(el)); }
#endif

  virtual const AttributeSignature* GetAttributeSignature(AttributeId) const;
  //virtual void Normalize(const SmartPtr<MathMLDocument>&);
  virtual void DoLayout(const class FormattingContext&);
  virtual void SetPosition(const scaled&, const scaled&);
  virtual void Setup(class RenderingEnvironment&);
  virtual void Render(const DrawingArea&);

  virtual bool IsSpaceLike(void) const;
  virtual void SetDirtyAttribute(void);
  virtual SmartPtr<class MathMLOperatorElement> GetCoreOperator(void);

  bool HasDifferentBackground(void) const { return differentBackground; }
  
private:
  bool differentBackground; // true if the background color is different from parent's one
};

#endif // MathMLStyleElement_hh
