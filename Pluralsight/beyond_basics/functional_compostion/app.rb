#!/usr/bin/env ruby
# encoding: UTF-8

require './lib/product'
require './lib/report'

prod = Product.new

200.times do
  prod.add({
    price: Faker::Number.number(4).to_i,
    rating: Faker::Number.digit.to_i,
    color: Faker::Color.color_name,
    sales: Faker::Number.number(8).to_i
  })
end

products = Product

sum = -> list { list.inject(&:+) }
sales_value = -> prods do
  product_revenue = prods.map { |product| product.sales * product.price }
  sum.(product_revenue)
end
total_sales = -> prods { sum.(prods.map(&:sales)) }
avg_sale_price = -> prods { sales_value.(prods) / total_sales.(prods) }
by_attribute = -> attr, op, value, prods do
  prods.select { |p| p[attr].send(op, value) }
end
by_color = by_attribute.curry[:color, :==]
by_max_rating = by_attribute.curry[:rating, :<=]

class FunctionalReport
  def initialize(products, *fns)
    @products = products
    @fns = fns
  end

  def run
    @fns.inject(@products) do |last_result, fn|
      fn[last_result]
    end
  end
end

freport = FunctionalReport.new(products.all, by_color.curry.('red'), by_max_rating.curry.(3))
p freport.run

report = Report.new(products.all)
p report.run
p report.top_selling(red_only: true)
