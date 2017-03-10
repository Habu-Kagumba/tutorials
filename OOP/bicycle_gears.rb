#!/usr/bin/env ruby
# encoding: UTF-8
class Gear
  attr_reader :chainring, :cog

  def initialize(args)
    args = defaults.merge(args)
    @chainring = args[:chainring]
    @cog = args[:cog]
  end

  def defaults
    {
      chainring: 40,
      cog: 18
    }
  end

  def ratio
    chainring / cog.to_f
  end

  def gear_inches(diameter)
    ratio * diameter
  end
end

class Wheel
  attr_reader :rim, :tire, :gear

  def initialize(args)
    @rim = args[:rim]
    @tire = args[:tire]
    @gear = Gear.new(args)
  end

  def diameter
    rim + (2 * tire)
  end

  def circumference
    diameter * Math::PI
  end

  def gear_inches
    gear.gear_inches(diameter)
  end
end

require'pry';binding.pry
