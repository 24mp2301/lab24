color_list1 = input("enter colors for list1 (comma seperated):").split(",")
color_list2 = input("enter colors for list2 (comma seperated):").split(",")

color_list1 = [color.strip() for color in color_list1]
color_list2 = [color.strip() for color in color_list2]

unique_colors = [color for color in  color_list1 if color not in color_list2]

print("colors in color_list1 not in colorlist2:",unique_colors)
