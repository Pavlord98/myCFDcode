

auto northMomentum(mn(cellNumber),par.uLid, bon.top)
{
  struct retVals{
    double anu;
    double spu;
    double suu1;
  };

  enum type {
    wall,
    movingWall,
    vInlet,
    pOutlet,
};

string_code hashit (std::string const& inString) {
    if (inString == "wall") return wall;
    if (inString == "movingWall") return movingWall;
    ...
}

void foo() {
    switch (hashit(stringValue)) {
    case eFred:
        ...
    case eBarney:
        ...
    }
}
}
