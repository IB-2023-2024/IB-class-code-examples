public class ConversorEurosPesetas extends ConversorEuros {
// Adaptador de clase
  public ConversorEurosPesetas () {
        super(166.386D);
  }
  public double eurosApesetas(double cantidad) {
        return eurosAmoneda(cantidad);
  }
  public double pesetasAeuros(double cantidad) {
        return monedaAeuros(cantidad);
  }
}

