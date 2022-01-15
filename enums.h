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
  creg
};

enum class GateType {
  unitary,
  opaque,
};