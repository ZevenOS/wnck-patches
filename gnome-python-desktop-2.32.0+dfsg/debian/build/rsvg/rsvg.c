/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#define PY_SSIZE_T_CLEAN
#include <Python.h>




#if PY_VERSION_HEX < 0x02050000
typedef int Py_ssize_t;
#define PY_SSIZE_T_MAX INT_MAX
#define PY_SSIZE_T_MIN INT_MIN
typedef inquiry lenfunc;
typedef intargfunc ssizeargfunc;
typedef intobjargproc ssizeobjargproc;
#endif


#line 4 "rsvg.override"
#include <Python.h>
#define NO_IMPORT_PYGOBJECT
#include <pygobject.h>

#include <pycairo.h>
extern Pycairo_CAPI_t *Pycairo_CAPI;

#include <glib.h>
#include <librsvg/rsvg.h>
#include <librsvg/rsvg-cairo.h>

#include "config.h"

#line 34 "rsvg.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyRsvgHandle_Type;

#line 45 "rsvg.c"



/* ----------- RsvgHandle ----------- */

#line 173 "rsvg.override"
static int
_wrap_rsvg_handle_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "file", "data", NULL };
    GError *error = NULL;
    RsvgHandle *handle;
    char *file = NULL;
    guint8 *data = NULL;
    Py_ssize_t data_len;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "|zs#:Handle.__init__",
                                     kwlist,
                                     &file, &data, &data_len))
        return -1;

    if (data != NULL && file != NULL) {
        PyErr_SetString(PyExc_ValueError,
            "data and file argument are mutually exclusive");
        return -1;
    }

    if (data != NULL) {
        /* Work around an assertion in librsvg in case data_len == 0. We
         * don't want the user see the ugly assertion output on the console.
         * Instead, throw a proper gobject.GError exception.
         */
        if (data_len == 0) {
            g_set_error(&error, rsvg_error_quark(), 0,
                "XML data must not be empty");
            pyg_error_check(&error);
            return -1;
        }
        handle = rsvg_handle_new_from_data(data, data_len, &error);
        if (pyg_error_check(&error))
            return -1;
    } else if (file != NULL) {
        handle = rsvg_handle_new_from_file(file, &error);
        if (pyg_error_check(&error))
            return -1;
    } else {
        handle = rsvg_handle_new();
    }

    /* Work around a librsvg problem, where handle can be NULL, without error
     * getting set.
     */
    if (handle == NULL) {
        PyErr_SetString(PyExc_RuntimeError, "unknown librsvg error");
        return -1;
    }

    self->obj = (GObject *) handle;

    pygobject_register_wrapper((PyObject *) self);
    return 0;
}
#line 109 "rsvg.c"


#line 59 "rsvg.override"
static PyObject *
_wrap_rsvg_handle_set_dpi(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "dpi_x", "dpi_y", NULL };
    double dpi_x, dpi_y = 0.0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "d|d:Handle.set_dpi",
                                     kwlist, &dpi_x, &dpi_y))
        return NULL;

    if (dpi_y == 0.0)
        rsvg_handle_set_dpi(RSVG_HANDLE(self->obj), dpi_x);
    else
        rsvg_handle_set_dpi_x_y(RSVG_HANDLE(self->obj), dpi_x, dpi_y);

    Py_INCREF(Py_None);
    return Py_None;
}

#line 133 "rsvg.c"


#line 81 "rsvg.override"
static PyObject *
_wrap_rsvg_handle_write(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "buffer", NULL };
    GError *error = NULL;
    const guchar *buffer;
    Py_ssize_t len;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "s#:Handle.write",
                                     kwlist, &buffer, &len))
        return NULL;

    rsvg_handle_write(RSVG_HANDLE(self->obj), buffer, len, &error);
    if (pyg_error_check(&error))
        return NULL;

    Py_INCREF(Py_None);
    return Py_None;
}

#line 158 "rsvg.c"


static PyObject *
_wrap_rsvg_handle_close(PyGObject *self)
{
    int ret;
    GError *error = NULL;

    
    ret = rsvg_handle_close(RSVG_HANDLE(self->obj), &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

#line 117 "rsvg.override"
static PyObject *
_wrap_rsvg_handle_get_pixbuf(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", NULL };
    const char *id = NULL;
    GdkPixbuf *pb;
    PyObject *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "|s:Handle.get_pixbuf",
                                     kwlist, &id))
        return NULL;

    if (id != NULL)
        pb = rsvg_handle_get_pixbuf_sub(RSVG_HANDLE(self->obj), id);
    else
        pb = rsvg_handle_get_pixbuf(RSVG_HANDLE(self->obj));

    if (pb == NULL) {
        Py_INCREF(Py_None);
        return Py_None;
    }

    ret = pygobject_new((GObject *) pb);
    g_object_unref(pb);
    return ret;
}

#line 205 "rsvg.c"


#line 147 "rsvg.override"
static PyObject *
_wrap_rsvg_handle_render_cairo(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "cr", "id", NULL };
    const char *id = NULL;
    PyObject *py_cr;
    cairo_t *cr;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "O!|s:Handle.render_cairo",
                                     kwlist,
                                     &PycairoContext_Type, &py_cr, &id))
        return NULL;

    cr = ((PycairoContext *) py_cr)->ctx;
    if (id != NULL)
        rsvg_handle_render_cairo_sub(RSVG_HANDLE(self->obj), cr, id);
    else
        rsvg_handle_render_cairo(RSVG_HANDLE(self->obj), cr);

    Py_INCREF(Py_None);
    return Py_None;
}

#line 233 "rsvg.c"


#line 104 "rsvg.override"
static PyObject *
_wrap_rsvg_handle_get_dimension_data(PyGObject *self)
{
    RsvgDimensionData dim_data;

    rsvg_handle_get_dimensions(RSVG_HANDLE(self->obj), &dim_data);

    return Py_BuildValue("(iidd)",
        dim_data.width, dim_data.height, dim_data.em, dim_data.ex);
}

#line 248 "rsvg.c"


static const PyMethodDef _PyRsvgHandle_methods[] = {
    { "set_dpi", (PyCFunction)_wrap_rsvg_handle_set_dpi, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "write", (PyCFunction)_wrap_rsvg_handle_write, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "close", (PyCFunction)_wrap_rsvg_handle_close, METH_NOARGS,
      NULL },
    { "get_pixbuf", (PyCFunction)_wrap_rsvg_handle_get_pixbuf, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "render_cairo", (PyCFunction)_wrap_rsvg_handle_render_cairo, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_dimension_data", (PyCFunction)_wrap_rsvg_handle_get_dimension_data, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyRsvgHandle_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "rsvg.Handle",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyRsvgHandle_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_rsvg_handle_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

#line 37 "rsvg.override"
static PyObject *
_wrap_rsvg_set_default_dpi(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "dpi_x", "dpi_y", NULL };
    double dpi_x, dpi_y = 0.0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "d|d:set_default_dpi",
                                     kwlist, &dpi_x, &dpi_y))
        return NULL;

    if (dpi_y == 0.0)
        rsvg_set_default_dpi(dpi_x);
    else
        rsvg_set_default_dpi_x_y(dpi_x, dpi_y);

    Py_INCREF(Py_None);
    return Py_None;
}

#line 337 "rsvg.c"


const PyMethodDef pyrsvg_functions[] = {
    { "set_default_dpi", (PyCFunction)_wrap_rsvg_set_default_dpi, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

/* initialise stuff extension classes */
void
pyrsvg_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gobject")) != NULL) {
        _PyGObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gobject");
        return ;
    }


#line 366 "rsvg.c"
    pygobject_register_class(d, "RsvgHandle", RSVG_TYPE_HANDLE, &PyRsvgHandle_Type, Py_BuildValue("(O)", &PyGObject_Type));
}
