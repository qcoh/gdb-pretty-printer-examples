import gdb.printing


class WordPrinter(object):
    """Pretty Printer for word type."""

    def __init__(self, val):
        self.val = val
        self.hi = int(val["m_hi"].referenced_value())
        self.lo = int(val["m_lo"].referenced_value())

    def to_string(self):
        return "0x{:02x}{:02x}".format(self.hi, self.lo)


def build_pretty_printer():
    pp = gdb.printing.RegexpCollectionPrettyPrinter("qcoh")
    pp.add_printer("word", "^word", WordPrinter)
    return pp


gdb.printing.register_pretty_printer(gdb.current_objfile(), build_pretty_printer())
