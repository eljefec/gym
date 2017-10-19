def calc_drone_min_energy(route):
  req_start_energy = 0
  tank = 0
  for i in range(len(route)):
    z = route[i][2]
    if i != 0:
      diff = z - prev_z
      if diff < 0:
        tank -= diff
      elif diff > 0:
        tank -= diff ###
        if tank < 0:
          req_start_energy += -tank
          tank = 0
    prev_z = z
  return req_start_energy

def test_calc():
  route = [ [0,   2, 10],
            [3,   5,  0],
            [9,  20,  6],
            [10, 12, 15],
            [10, 10,  8]]

  # i, z, prev_z, tank, req_start_energy
  # 0, 10, 10, 0
  # 1, 0, 10, 10
  # 2, 6, 0, 4
  # 3, 15, 6, -5, 5
  #            0
  # 4: 8, 15, 7
  # req_start_energy: 5

  assert(5 == calc_drone_min_energy(route))
  assert(0 == calc_drone_min_energy([[0, 2, 10]]))
  assert(0 == calc_drone_min_energy([[0, 2, 10], [0, 2, 10], [0, 2, 10]]))
  assert(2 == calc_drone_min_energy([[0, 2, 1], [0, 2, 2], [0, 2, 3]]))
  assert(0 == calc_drone_min_energy([[0, 2, 3], [0, 2, 2], [0, 2, 1]]))

if __name__ == '__main__':
  test_calc()
