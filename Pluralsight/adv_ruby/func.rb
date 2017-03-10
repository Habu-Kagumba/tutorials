product = Struct.new("Product", :price, :sales, :rating, :color)

class Report
  def initialize(products)
    @products = products
  end

  def run(red_only: false)
    money_taken = select_products(red_only).inject(0) do |total, product|
      (product.price * product.sales) + total
    end

    total_sales = select_products(red_only).inject(0) do |total, product|
      product.sales + total
    end

    {
      average_sales_price: money_taken / total_sales,
      money_taken: money_taken
    }
  end

  def top_selling(red_only: false)
    select_products(red_only).sort_by(&:sales).last(3)
  end

  def select_products(red_only)
    selection = @products

    if red_only
      selection = selection.select { |product| product.color == :red }
    end

    selection
  end
end

prods = []
prods.push product.new(10, 2251, 1, :green)
prods.push product.new(100, 251, 0, :blue)
prods.push product.new(50, 233351, 1, :red)

p Report.new(prods).run
p Report.new(prods).run(red_only: true)
p Report.new(prods).top_selling(red_only: true)
