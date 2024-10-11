from PIL import ImageDraw, ImageFont

# Create a drawing object to modify the image
draw = ImageDraw.Draw(image)

# Coordinates where "Renewable Energy" and "Cyber Law" texts are located (approximate)
# These coordinates are determined manually based on the position of the text in the image.
renewable_energy_coords = [(215, 135), (200, 275), (200, 380)]  # Approx positions for Renewable Energy
cyber_law_coords = [(470, 380), (470, 185)]  # Approx positions for Cyber Law

# Function to white out the text area (cover text with white rectangle)
def white_out_text(coords, width, height):
    for coord in coords:
        draw.rectangle([coord, (coord[0] + width, coord[1] + height)], fill="white")

# White out Renewable Energy and Cyber Law
white_out_text(renewable_energy_coords, 120, 30)  # Approx width and height for Renewable Energy text
white_out_text(cyber_law_coords, 100, 30)  # Approx width and height for Cyber Law text

# Save the modified image
modified_image_path = "/mnt/data/modified_timetable.jpeg"
image.save(modified_image_path)

modified_image_path  # Return the path of the modified image
