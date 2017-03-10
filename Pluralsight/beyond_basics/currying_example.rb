#!/usr/bin/env ruby
# encoding: UTF-8

class Promotion
  def initialize(description, calculator)
    @description = description
    @calculator = calculator
  end

  def apply(total)
    total - @calculator.(total)
  end
end

calc = -> threshold, discount, total do
  total > threshold ? total * discount : 0
end

ten_pc_calc  = calc.curry.(50, 0.1)
fifteen_pc_calc = calc.curry.(100, 0.15)

ten_pc = Promotion.new(
  '10% discount',
  ten_pc_calc
)

fifteen_pc = Promotion.new(
  '15% discount',
  fifteen_pc_calc
)

p ten_pc.apply(45)
p ten_pc.apply(100)
p fifteen_pc.apply(100)
p fifteen_pc.apply(300)
