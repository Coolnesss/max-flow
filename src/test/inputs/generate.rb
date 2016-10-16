vertices, edges = ARGV.map(&:to_i)
puts "#{vertices} #{edges}"

def rek(start, finish, amount) 
    puts "#{start} #{amount}"
    puts "#{start} 3 #{amount}"
    puts "2 #{finish} #{amount}"
    puts "3 #{finish} #{amount}"
end


edges.times do |i|
    v = rand(vertices) + 1 
    u = rand(vertices) + 1
    
    while v == u or u == vertices or u == 1
        u = rand(vertices) + 1 
        v = rand(vertices) + 1
    end

    if (i % 2 == 0) 
        puts "#{v} #{u} #{rand(99999999) + 1}"
    else
        puts "#{v} #{u} 1"
    end
end