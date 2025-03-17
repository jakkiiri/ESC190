from PIL import Image, ImageEnhance

def create_brightness_gif(input_path, output_path, num_frames=10, min_factor=0.3, max_factor=1.5, frame_duration=100):
    """
    Create a GIF showing an image getting progressively brighter.
    
    Args:
        input_path: Path to input image
        output_path: Path to save output GIF
        num_frames: Number of frames in animation
        min_factor: Starting brightness (0 = black, 1 = original)
        max_factor: Ending brightness (1 = original, >1 = brighter)
        frame_duration: Milliseconds to display each frame
    """
    # Open and convert image to RGB mode
    base_image = Image.open(input_path).convert("RGB")
    
    # Generate brightness factors from dark to bright
    brightness_factors = [min_factor + (max_factor - min_factor) * i/(num_frames-1) 
                          for i in range(num_frames)]
    
    # Create enhanced frames
    frames = []
    for factor in brightness_factors:
        enhancer = ImageEnhance.Brightness(base_image)
        frame = enhancer.enhance(factor)
        frames.append(frame)
    
    # Save as animated GIF
    frames[0].save(
        output_path,
        save_all=True,
        append_images=frames[1:],
        duration=frame_duration,
        loop=0  # 0 = infinite loop
    )

# Example usage
create_brightness_gif(
    input_path="cannon.jpg",
    output_path="brightness_animation.gif",
    num_frames=15,
    min_factor=0.3,
    max_factor=1.8,
    frame_duration=80
)