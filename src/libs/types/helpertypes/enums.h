enum class RegisterType {
  quantum,
  classical
};

enum class ParamType {
  theta,
  phi,
  lambda
};

enum class ArgumentType {
  qubit, 
  qreg, 
  bit, 
  creg,
  quantum,
  classical
};

enum class GateType {
  unitary,
  opaque,
};