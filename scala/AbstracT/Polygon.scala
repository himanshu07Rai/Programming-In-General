package AbstracT

abstract class Polygon{
  def area :Double
}

object Polygon{
  def main(args:Array[String]):Unit={
//    var poly = new Polygon
    var rect = new Rectangle(2,7)
    var tri = new Triangle(4,3)
    printArea(tri)
  }

  def printArea(p:Polygon):Unit={
    println(p.area)
  }
}