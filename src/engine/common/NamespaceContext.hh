// Copyright (C) 2000-2004, Luca Padovani <luca.padovani@cs.unibo.it>.
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
// http://helm.cs.unibo.it/mml-widget/, or send a mail to
// <lpadovan@cs.unibo.it>

#ifndef __NamespaceContext_hh__
#define __NamespaceContext_hh__

#include "Object.hh"
#include "SmartPtr.hh"
#include "WeakPtr.hh"
#include "String.hh"

class NamespaceContext : public Object
{
protected:
  NamespaceContext(const String&);
  virtual ~NamespaceContext();

public:
  String getNamespaceURI(void) const { return namespaceURI; }
  SmartPtr<class View> getView(void) const;

  // virtual SmartPtr<class Element> construct(class AbstractReader&) const = 0;
  virtual SmartPtr<class Element> construct(const DOM::Element&) const = 0;
  virtual SmartPtr<const class Area> format(const SmartPtr<class Element>&) const = 0;

private:
  WeakPtr<class View> view;
  const String namespaceURI;
};

#endif // __NamespaceContext_hh__
