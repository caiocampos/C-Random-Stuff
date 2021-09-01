package javaserver;

import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.transport.TSSLTransportFactory.*;
import org.apache.thrift.protocol.*;
import shared.*;
import tutorial.*;

public class JavaClient {
  public static void main(String [] args) {
    if (args.length != 1) {
      System.out.println("Erro");
      System.exit(0);
    }
    try {
      TTransport transport;
      transport = new TSocket("localhost", new Integer(args[0]));
      transport.open();
      TProtocol protocol = new  TBinaryProtocol(transport);
      Calculator.Client client = new Calculator.Client(protocol);
      perform(client);
      transport.close();
    } catch (TException x) {
    }
  }

  private static void perform(Calculator.Client client) throws TException
  {
    client.ping();
    System.out.println("ping()");
    int sum = client.add(1,1);
    System.out.println("1+1=" + sum);
    Work work = new Work();
    work.op = Operation.DIVIDE;
    work.num1 = 1;
    work.num2 = 0;
    try {
      int quotient = client.calculate(1, work);
      System.out.println("Whoa we can divide by 0");
    } catch (InvalidOperation io) {
      System.out.println("Invalid operation: " + io.why);
    }
    work.op = Operation.SUBTRACT;
    work.num1 = 15;
    work.num2 = 10;
    try {
      int diff = client.calculate(1, work);
      System.out.println("15-10=" + diff);
    } catch (InvalidOperation io) {
      System.out.println("Invalid operation: " + io.why);
    }
    SharedStruct log = client.getStruct(1);
    System.out.println("Check log: " + log.value);
  }
}