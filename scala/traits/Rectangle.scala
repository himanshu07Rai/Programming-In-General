package inheritance

class Rectangle(w:Double,h:Double) extends Polygon {
  override def area:Double = w*h
}

object Rectangle{
  def main(args:Array[String]): Unit ={
    println("Hi")
  }
}