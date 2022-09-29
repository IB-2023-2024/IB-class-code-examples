import java.awt.*;
import javax.swing.*;
//import java.awt.event.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class VentanaConversor extends JFrame implements InterfazVista {
	private JButton convertirApesetas;
	private JButton convertirAeuros;
	private JTextField cantidad;
	private JLabel resultado;
	public VentanaConversor () {
		super("Conversor de Euros y Pesetas");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JPanel panelPrincipal = new JPanel();
		panelPrincipal.setLayout(new BorderLayout(10,10));
		cantidad = new JTextField(8);
		JPanel panelaux = new JPanel(); panelaux.add(cantidad);
		panelPrincipal.add(panelaux, BorderLayout.NORTH);
		resultado = new JLabel("Indique una cantidad y pulse uno de los botones");
		JPanel panelaux2 = new JPanel(); panelaux2.add(resultado);
		panelPrincipal.add(panelaux2, BorderLayout.CENTER);
		convertirApesetas = new JButton("A pesetas");
		convertirApesetas.setActionCommand(APESETAS);
		convertirAeuros = new JButton("A euros");
		convertirAeuros.setActionCommand(AEUROS);
		JPanel botonera = new JPanel();
		botonera.add(convertirApesetas); botonera.add(convertirAeuros);
		panelPrincipal.add(botonera, BorderLayout.SOUTH);
		getContentPane().add(panelPrincipal);
	}

// Métodos de la interfaz InterfazVista:
public void escribeCambio(String s) {
        resultado.setText(s);
}
public double getCantidad() {
        try {
                return Double.parseDouble(cantidad.getText());
        }
        catch (NumberFormatException e) {
                return 0.0D;
        }
}

public void setControlador(ControlConversor c) {
        convertirApesetas.addActionListener(c);
        convertirAeuros.addActionListener(c);
}
public void arranca() {
        pack();// coloca los componentes
        setLocationRelativeTo(null);// centra la ventana en la pantalla
        setVisible(true);// visualiza la ventana
}

}

