// Copyright (C) 2000-2003, Luca Padovani <luca.padovani@cs.unibo.it>.
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
// http://helm.cs.unibo.it/mml-widget, or send a mail to
// <luca.padovani@cs.unibo.it>

#ifndef MathMLGlyphNode_hh
#define MathMLGlyphNode_hh

#include "MathMLTextNode.hh"

class MathMLGlyphNode : public MathMLTextNode
{
protected:
  MathMLGlyphNode(const String&, const String&, const String&);
  virtual ~MathMLGlyphNode();

public:
  static SmartPtr<MathMLGlyphNode> create(const String& family, const String& index, const String& alt)
  { return new MathMLGlyphNode(family, index, alt); }

#if 0
  virtual void 	   Setup(class RenderingEnvironment&);
  virtual void 	   DoLayout(const class FormattingContext&);
#endif
  virtual AreaRef format(class MathFormattingContext&);
#if 0
  virtual void 	   Render(const DrawingArea&);
#endif

  virtual unsigned GetLogicalContentLength(void) const;

protected:
  String family;
  String index;
  String alt;
};

#endif // MathMLGlyphNode_hh
