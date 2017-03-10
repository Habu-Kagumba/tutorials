#!/usr/bin/env ruby
# encoding: UTF-8
require 'ox'

module RXT
  class Template
    def self.from_file(path)
      new(File.read(path), path)
    end

    def initialize(rxt_source, filename='(rxt)', lineno=1)
      @block = CleanBinding.get.eval(<<~END_SOURCE, filename, lineno-1)
        Proc.new do
          #{rxt_source}
        end
      END_SOURCE
    end

    def render(instance_variables={})
      dsl = DSL.new

      instance_variables.each do |name, value|
        dsl.instance_variable_set("@#{name}", value)
      end

      dsl.instance_eval(&@block)

      root = dsl.__root
      Ox.dump(root, with_xml: root.attributes.any?)
    end

    module CleanBinding
      def self.get
        binding
      end
    end
  end
end
