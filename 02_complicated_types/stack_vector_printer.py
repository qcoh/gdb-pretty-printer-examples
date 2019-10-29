import gdb.printing


class StackVectorPrinter(object):
    """Pretty Printer for stack::vector."""

    def __init__(self, val):
        self.val = val

        self.value_type = self.val.type.template_argument(0)
        self.capacity = self.val.type.template_argument(1)

        self.m_length = int(self.val["m_length"])
        self.m_data = self.val["m_data"].cast(self.value_type.pointer())

    def children(self):
        """Return tuple of name and value of children."""
        return [("[{}]".format(i), self.m_data[i]) for i in range(self.m_length)]

    def to_string(self):
        """Prefix for children output."""

        return "fs::vector<{}, {}> of length {}".format(
            self.value_type, self.capacity, self.m_length
        )

    def display_hint(self):
        # return "string"
        return "array"
        # return "map"


def build_pretty_printer():
    pp = gdb.printing.RegexpCollectionPrettyPrinter("qcoh")
    pp.add_printer("stack::vector", "^stack::vector", StackVectorPrinter)
    return pp


gdb.printing.register_pretty_printer(gdb.current_objfile(), build_pretty_printer())
