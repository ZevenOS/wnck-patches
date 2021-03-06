/*  evolution-python: Python bindings to libecal and libebook
 *  Copyright (c) 2007 John Stowers <john.stowers@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <pygobject.h>

void pyebook_register_classes(PyObject *d);
void pyebook_add_constants(PyObject *m, const gchar *strip_prefix);

extern PyMethodDef pyebook_functions[];
extern PyObject PyEBookQuery_Type;

DL_EXPORT(void)
initebook(void)
{
    PyObject *m, *d;

    if (!pygobject_init(-1, -1, -1))
        return;
    PyImport_ImportModule("bonobo");
    if (PyErr_Occurred())
        return;    
	
    m = Py_InitModule("ebook", pyebook_functions);
    d = PyModule_GetDict(m);
    
    pyebook_register_classes(d);

    pyebook_add_constants(m, "E_");

    PyModule_AddObject(m, "__version__",
#ifdef HAVE_CONFIG_H
                        Py_BuildValue("iii",
                            GNOME_PYTHON_DESKTOP_MAJOR_VERSION,
                            GNOME_PYTHON_DESKTOP_MINOR_VERSION,
                            GNOME_PYTHON_DESKTOP_MICRO_VERSION)
#else
                        Py_BuildValue("iii",0,0,0)
#endif
                        );
    
    PyModule_AddObject(m, "EBookQuery", (PyObject *)&PyEBookQuery_Type);

    if (PyErr_Occurred())
        Py_FatalError("could not initialise module _ebook");
}
